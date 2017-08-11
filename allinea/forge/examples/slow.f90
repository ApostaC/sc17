program slow
use mpi
implicit none
integer :: pe, nprocs, ierr

call MPI_INIT(ierr)
call MPI_COMM_RANK(MPI_COMM_WORLD, pe, ierr)
call MPI_COMM_SIZE(MPI_COMM_WORLD, nprocs, ierr)

call imbalance
call stride
call overlap

call MPI_FINALIZE(ierr)

contains

subroutine overlap

  implicit none
  integer :: from,count,j, index, iterations
  real(kind=8)    :: a(3000000),b(3000000)
  integer :: reqs(nprocs-1)
  integer :: stat(mpi_status_size)
      
  if (pe == 0) print *,"inflexible approach"
  do iterations=1,2
    a(:) = 1000.0*real(pe+2.0)
    if (pe == 1) then
      ! late to the party
      do j=1,20*nprocs; a=sqrt(a)*sqrt(a+1.1); end do
    end if
    
    if (pe /= 0) then
      call MPI_SEND(a, size(a), MPI_REAL, 0, 1, MPI_COMM_WORLD, ierr)
    else
      do from=1,nprocs-1
        call MPI_RECV(b, size(b), MPI_REAL, from, 1, MPI_COMM_WORLD, stat, ierr)
        do j=1,50; b=sqrt(b)*sqrt(b+1.1); end do
        print *,"Answer from",from,sum(b)
      end do
    end if
  end do
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)
  
  if (pe == 0) print *,"flexible approach"
  do iterations=1,2
    a(:) = 1000.0*real(pe+2.0)
    if (pe == 1) then
      ! late to the party
      do j=1,20*nprocs; a=sqrt(a)*sqrt(a+1.1); end do
    end if
    
    if (pe /= 0) then
      call MPI_SEND(a, size(a), MPI_REAL, 0, 1, MPI_COMM_WORLD, ierr)
    else
      do from=1,nprocs-1
        call MPI_IRECV(b, size(b), MPI_REAL, from, 1, MPI_COMM_WORLD, reqs(from), ierr)
      end do
      count = 0
      do while (count < nprocs -1) 
        call MPI_WAITANY(nprocs-1,reqs, index, stat,ierr)
        from=index+1
        count = count + 1
        do j=1,50;b=sqrt(b)*sqrt(b+1.1);end do
        print *,"Answer from",from,sum(b)
      end do
    end if
  end do
  if (pe == 0) print *,"overlap answer",b(1)
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

end subroutine overlap

subroutine imbalance

  integer :: i,j,iterations
  real(kind=8)    :: a(20000),b(20000)

  do iterations=1,4
    a=1.1 + iterations
    do j=0,pe
      do i=1,size(a)
         a=sqrt(a)+1.1*j
      end do
    end do
    call MPI_ALLREDUCE(a,b,size(a),MPI_REAL,MPI_SUM,MPI_COMM_WORLD,ierr)
  end do
  if (pe == 0) print *,"imbalance answer",b(1)
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

end subroutine imbalance

subroutine stride

  implicit none
  real(kind=8) :: arr_in(8000,2000)
  real(kind=8) :: arr_out(8000,2000)
  integer :: i,j,l

  arr_in = 4.2 ! dummy data

  ! inefficient memory access pattern (incrementing j in the inner loop)
  ! note: some compilers are able to optimize this trivial example by reordering
  ! the inner loops - in that case recompile with -O0 instead of the default -O3
  do l=1,150
    do i=1,8000
      do j=1,2000
        arr_out(i,j) = sqrt(arr_in(i,j) - arr_in(i,j)) + sqrt(arr_in(i,j) + arr_in(i,j))
        arr_out(i,j) = arr_out(i,j) * arr_out(i,j)
      end do
    end do
  end do

  ! on a busy workstation some processes often finish faster and wait here
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

  ! efficient memory access pattern (incrementing i in the inner loop)
  do l=1,150
    do j=1,2000
      do i=1,8000
        arr_out(i,j) = sqrt(arr_in(i,j) - arr_in(i,j)) + sqrt(arr_in(i,j) + arr_in(i,j))
        arr_out(i,j) = arr_out(i,j) * arr_out(i,j)
      end do
    end do
  end do

  if (pe == 0) print *,"stride answer",sum(arr_out)
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

end subroutine stride

subroutine power

  implicit none
  integer :: i,two,three,four
  real(kind=8) :: a,b

  a=1.1
  do i=1,200000000
    b=a**2
    b=a**3
    b=a**4
  end do

  two=2
  three=3
  four=4
  do i=1,200000000
    b=a**two
    b=a**three
    b=a**four
  end do

  if (pe == 0) print *,"power answer",b
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

end subroutine power

end program slow
