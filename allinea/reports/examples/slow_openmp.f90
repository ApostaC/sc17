program slow
use mpi
use omp_lib
implicit none
integer :: pe, nprocs, ierr, thread_support

call MPI_INIT_THREAD(MPI_THREAD_FUNNELED, thread_support, ierr)
call MPI_COMM_RANK(MPI_COMM_WORLD, pe, ierr)
call MPI_COMM_SIZE(MPI_COMM_WORLD, nprocs, ierr)

call imbalance
call stride

call MPI_FINALIZE(ierr)

contains

subroutine overlap

  implicit none
  integer :: from,count,j, index, iterations
  real    :: a(500000),b(500000)
  integer :: reqs(nprocs-1)
  integer :: stat(mpi_status_size)
      
  if (pe == 0) print *,"inflexible approach"
  do iterations=1,1
!$omp parallel
!$omp workshare
    a(:) = 1000.0*real(pe+2.0)
!$omp end workshare

    if (pe == 1) then
      ! late to the party
!$omp do
      do j=1,500*nprocs; a=sqrt(a)*sqrt(a+1.1); end do
!$omp end do
    end if
!$omp end parallel

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
  do iterations=1,1
!$omp parallel
!$omp workshare
    a(:) = 1000.0*real(pe+2.0)
!$omp end workshare

    if (pe == 1) then
      ! late to the party
!$omp do
      do j=1,500*nprocs; a=sqrt(a)*sqrt(a+1.1); end do
!$omp end do
    end if
!$omp end parallel

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
  real    :: a(20000),b(20000)

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
  real :: a(1000,1000)
  integer :: i,j,l
  real :: x,y

  ! inefficient
!$omp parallel
!$omp do
  do l=1,400
    do i=1,1000
      do j=1,1000
        x=i
        y=j
        a(i,j)=x*j
      end do
    end do
  end do
!$omp end do
!$omp end parallel

  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

  ! efficient
!$omp parallel
!$omp do
  do l=1,400
    do j=1,1000
      do i=1,1000
        x=i
        y=j
        a(i,j)=x*j
      end do
    end do
  end do
!$omp end do
!$omp end parallel

  if (pe == 0) print *,"stride answer",sum(a)
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

end subroutine stride

subroutine power

  implicit none
  integer :: i,two,three,four
  real :: a,b

  a=1.1
  do i=1,200000000
    b=a**2
    b=a**3
    b=a**4
  end do

  two=2
  three=3
  four=4
  do i=1,199999998
    b=a**two
    b=a**three
    b=a**four
  end do

  if (pe == 0) print *,"power answer",b
  call MPI_BARRIER(MPI_COMM_WORLD,ierr)

end subroutine power

end program slow
