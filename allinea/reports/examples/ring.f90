program ring

use MPI, only : &
  MPI_STATUS_SIZE, &
  MPI_INTEGER, &
  MPI_COMM_WORLD

implicit none
integer :: pe, nprocs, tag, to, from, loops, ierr
integer :: i,j
real :: a
integer :: status(MPI_STATUS_SIZE)

call MPI_INIT(ierr)
call MPI_COMM_RANK(MPI_COMM_WORLD, pe, ierr)
call MPI_COMM_SIZE(MPI_COMM_WORLD, nprocs, ierr)

tag = 1
to = mod((pe + 1), nprocs)
from = mod((pe + nprocs - 1), nprocs)

if (pe == 0) then
  loops = 5 ! how many times round the ring
  call MPI_SEND(loops, 1, MPI_INTEGER, to, tag, MPI_COMM_WORLD, ierr)
end if
  
! If I get loops=0, pass on one more time, but give up myself

do while (.true.)
  call MPI_RECV(loops, 1, MPI_INTEGER, from, tag, MPI_COMM_WORLD, &
    status, ierr)

  if (pe == 0) then
    loops = loops - 1
  endif
  
  ! delaying tactics
  a=2.2
  do i=1,100000000;a=sqrt(a)+2.2;end do

  print *,"pe",pe,"calculated",a,"for loop",loops

  call MPI_SEND(loops, 1, MPI_INTEGER, to, tag, MPI_COMM_WORLD, ierr)
      
  if (loops == 0) exit
end do

! one last recv to finish

if (pe == 0) then
  call MPI_RECV(loops, 1, MPI_INTEGER, from, tag, MPI_COMM_WORLD, &
    status, ierr)
end if

if (pe==0) print *,"ring finished"
call MPI_FINALIZE(ierr)

end program
      
