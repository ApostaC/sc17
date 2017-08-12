Program openmp

  Use mpi

  Implicit None

  Integer, Parameter :: levs=100
  Integer, Parameter :: repeats=1000
  Integer, Parameter :: xm=100
  Integer, Parameter :: ym=100

  Integer :: ierr, threads, thread, mpiprovided
  Integer :: T(16)
  Integer :: CR

  Integer :: rank,nproc
  Integer :: p,rpt
  Real    :: scale,scale1

  Integer, Allocatable :: Comm(:)
  Real, Allocatable :: random1(:,:,:)
  Real, Allocatable :: a(:,:,:)
  Real, Allocatable :: b(:,:,:)
  Real, Allocatable :: c(:,:,:)
  Real, Allocatable :: d(:,:,:)
  Integer :: i,j,k

  !$ Integer, External :: omp_get_max_threads

  Allocate(random1(xm,ym,levs))
  Allocate(a(xm,ym,levs))
  Allocate(b(xm,ym,levs))
  Allocate(c(xm,ym,levs))
  Allocate(d(xm,ym,levs))

  Call System_Clock( &
    Count_rate=CR)

  Call MPI_INIT_THREAD(MPI_THREAD_FUNNELED,mpiprovided,ierr)

  threads=1
  !$ threads=omp_get_max_threads()

  thread=0

  Call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
  Call MPI_COMM_SIZE(MPI_COMM_WORLD, nproc, ierr)

  Allocate (comm(0:threads-1))

  comm(0) = MPI_COMM_WORLD
  Do i=1,SIZE(comm)-1
    Call mpi_comm_dup(comm(0), comm(i),ierr)
  End Do

  If (rank==0) Then
    Write (*,'(A,I0,A)') "openmp running with ",threads," threads"
  End If
  
  Call random_number(random1)
  
  c(:,:,:)=random1(:,:,:)
  d(:,:,:)=random1(:,:,:)

  p=1

  Call System_Clock(Count=T(p));p=p+1

  ! Do the initial assignments threaded so the 
  ! allocation is spread across threads

  !$OMP PARALLEL WORKSHARE
  a(:,:,:)=random1(:,:,:)
  !$OMP END PARALLEL WORKSHARE

  !$OMP PARALLEL WORKSHARE
  b(:,:,:)=random1(:,:,:)
  !$OMP END PARALLEL WORKSHARE

  Call System_Clock(Count=T(p));p=p+1

  Do rpt=1,repeats
    !$OMP PARALLEL DO SCHEDULE(STATIC) PRIVATE(i,j,k)
    Do k=1,levs
      Do j=1,ym
        Do i=1,xm
          a(i,j,k) = 1.0/a(i,j,k) + b(i,j,k)
        End Do
      End Do
    End Do
    !$OMP END PARALLEL DO
  End Do

  Call System_Clock(Count=T(p));p=p+1

  Do rpt=1,repeats
    !$OMP PARALLEL WORKSHARE
    a=1.0/a+b
    !$OMP END PARALLEL WORKSHARE
  End Do

  Call System_Clock(Count=T(p));p=p+1

  Do rpt=1,repeats
    !$OMP PARALLEL DO SCHEDULE(STATIC) PRIVATE(i,j,k)
    Do k=1,levs
      Do j=1,ym
        Do i=1,xm
          c(i,j,k) = 1.0/c(i,j,k) + d(i,j,k)
        End Do
      End Do
    End Do
    !$OMP END PARALLEL DO
  End Do

  Call System_Clock(Count=T(p));p=p+1

  scale1=Real(xm*ym*levs)*Real(CR)/1000000.0
  scale=Real(repeats)*Real(xm*ym*levs)*Real(CR)/1000000.0

  If (rank==0) Then
    p=1  ; Write (*,'(F12.2,A)') scale1/Real(T(p+1)-T(p))," openmp initial assignments/s"
    p=p+1; Write (*,'(F12.2,A)') scale/Real(T(p+1)-T(p))," openmp 3d loops/s"
    p=p+1; Write (*,'(F12.2,A)') scale/Real(T(p+1)-T(p))," openmp 3d workshares/s"
    p=p+1; Write (*,'(F12.2,A)') scale/Real(T(p+1)-T(p))," openmp 3d touched workshares/s"
  End If
  
  If (mpiprovided == MPI_THREAD_MULTIPLE) Then
    Call ring
  End If

  Deallocate(random1)
  Deallocate(a)
  Deallocate(b)
  Deallocate(c)
  Deallocate(d)

  If (rank==0) Write(*,'(A)') "openmp finished"

  Call MPI_FINALIZE(ierr)

Contains

Subroutine Ring

  Implicit None
  
  Integer :: tag, to, from,loops,thread
  Integer :: i,j,T(2),p,rpt
  Real :: a
  Integer :: status(MPI_STATUS_SIZE)
  !$ Integer, External :: omp_get_thread_num
  
  tag = 1
  to = Mod((rank + 1), nproc)
  from = Mod((rank + nproc - 1), nproc)
    
  p=1;Call System_Clock(Count=T(p));p=p+1
  
  !$OMP PARALLEL PRIVATE(loops,thread,ierr,a,rpt,status)
  a=2.2
    thread=0
    !$ thread=omp_get_thread_num()
    
    If (rank == 0) Then
      loops = thread+1 ! Some threads go more times round the ring  
      Call MPI_SEND(loops, 1, MPI_INTEGER, to, tag, comm(thread), ierr)
    End If

    ! If I get loops=0, pass on one more time, but give up myself
    
    Do While (.true.)
      Call MPI_RECV(loops, 1, MPI_INTEGER, from, tag, comm(thread), &
        status, ierr)
    
      If (rank == 0) Then
        loops = loops - 1
      End If
    
      ! delaying tactics
      Do i=1,40000000;a=sqrt(a)+2.2; End Do
    
      Call MPI_SEND(loops, 1, MPI_INTEGER, to, tag, comm(thread), ierr)
    
      If (loops == 0) Exit
    End Do
    
    ! one last recv to finish
    
    If (rank == 0) Then
      Call MPI_RECV(loops, 1, MPI_INTEGER, from, tag, comm(thread), &
        status, ierr)
    End If   
  !$OMP END PARALLEL
    
  Call System_Clock(Count=T(p));p=p+1
  
  If (rank == 0) Then
    p=1; Write (*,'(F12.2,A)') Real(T(p+1)-T(p))," rings/s"
  End If

End subroutine Ring

End Program openmp
