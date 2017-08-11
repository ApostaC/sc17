! ****************************************************************************
!  FILE: wave.f90
!  DESCRIPTION:
!    MPI Concurrent Wave equation  - Fortran Example
!    This program implements the concurrent wave equation described 
!    in Chapter 5 of Fox et al., 1988, Solving Problems on Concurrent
!    Processors, vol 1.  
!    A vibrating string is decomposed into points.  Each processor is 
!    responsible for updating the amplitude of a number of points over
!    time. At each iteration, each processor exchanges boundary points with
!    nearest neighbors.  This version uses low level sends and receives
!    to exchange boundary points.
! AUTHOR: Blaise Barney. Adapted from Ros Leibensperger, Cornell Theory
!   Center. Converted to MPI: George L. Gusciora, MHPCC (1/95)  
! LAST REVISED: 12/20/2001 Blaise Barney
! ****************************************************************************
!  Explanation of constants and variables used in common blocks and
!  include files
!    MASTER           = task ID of master
!    E_OUT1, E_OUT2   = message types
!    taskid           = task ID
!    numtasks         = number of tasks
!    tpoints          = total points along wave
!    nsteps           = number of time steps
!    npoints          = number of points handled by this task
!    first            = index of first point handled by this task
!    values(0:1000001)   = values at time t
!    oldval(0:1000001)   = values at time (t-dt)
!    newval(0:1000001)   = values at time (t+dt)

module mod1
  integer :: npoints, first, tpoints, nsteps
  integer :: taskid, numtasks

  real*8 :: values(0:1000001), oldval(0:1000001), newval(0:1000001)
  
end module mod1

module wave  
  include "waveinc.f90"
  
contains

subroutine init_master
  !---------------------------------------------------------------------
  ! Master obtains input values from user
  !--------------------------------------------------------------------- 
  
  use mpi, only : MPI_INTEGER,MPI_COMM_WORLD
    
  use mod1, only : &
    taskid, numtasks, tpoints, nsteps

  implicit none

  integer, parameter :: MAXPOINTS = 1000000
  integer, parameter :: MAXSTEPS  = 100000
  integer :: ierr
  integer :: buffer(2)

  tpoints = MAXPOINTS
  nsteps = MAXSTEPS
  
  print *, 'Starting wave using', numtasks, 'tasks.'
  print *, 'Using',tpoints,'points on the vibrating string.'
  write (6,'(I8, ": points = ", I8, " running for ", f8.1, " seconds")') &
    taskid, tpoints, DURATION

  ! Broadcast total points, time steps
  buffer(1) = tpoints
  buffer(2) = nsteps
  call MPI_BCAST(buffer, 2, MPI_INTEGER, MASTER, MPI_COMM_WORLD, &
    ierr)
end subroutine init_master

subroutine init_workers
  !---------------------------------------------------------------------
  ! Workers receive input values from master
  !---------------------------------------------------------------------
  
  use mpi, only : MPI_INTEGER,MPI_COMM_WORLD
  
  use mod1, only : &
    taskid, numtasks, tpoints, nsteps
      
  implicit none

  integer :: buffer(2)
  integer :: ierr

  ! Receive time advance parameter, total points, time steps
  call MPI_BCAST(buffer, 2, MPI_INTEGER, MASTER, MPI_COMM_WORLD, &
    ierr)
  tpoints = buffer(1)
  nsteps =  buffer(2)

end subroutine init_workers

subroutine init_line
  !---------------------------------------------------------------------
  ! Initialize points on line
  !---------------------------------------------------------------------
  
  use mod1, only : &
    taskid, numtasks, tpoints, nsteps, npoints, first,values, oldval, &
    newval

  implicit none
  
  real*8, parameter :: PI=3.14159265
  integer :: nmin, nleft, npts, i, j, k
  real*8 :: x, fac

  ! Calculate initial values based on sine curve
  nmin = tpoints/numtasks
  nleft = mod(tpoints, numtasks)
  fac = 2.0 * PI

  k = 0
  do i = 0, numtasks-1
    if (i < nleft) then
      npts = nmin + 1
    else
      npts = nmin
    end if
    if (taskid == i) then
      first = k + 1
      npoints = npts
      write (6,'("task=",I8, ": first = ", I8, " npoints = ", I8)') &
        taskid, first, npts
      do j = 1, npts
        x = float(k)/float(tpoints - 1)
        values(j) = sin (fac * x)
        k = k + 1
      end do
    else 
       k = k + npts
    end if
  end do
  do i = 1, npoints
     oldval(i) = values(i)
  end do
end subroutine init_line

subroutine out_master
  !---------------------------------------------------------------------
  ! Receive results from workers and print
  ! --------------------------------------------------------------------
  
  use mpi, only : MPI_STATUS_SIZE, MPI_INTEGER, MPI_DOUBLE_PRECISION,MPI_COMM_WORLD
  
  use mod1, only : &
    taskid, numtasks, tpoints, nsteps, npoints, first,values, oldval, &
    newval

  implicit none

  integer ::  i, j, start, npts, buffer(2)
  integer :: status(MPI_STATUS_SIZE), ierr
  real*8 :: results(0:1000001)

  ! Store worker's results in results array
  do i = 1, numtasks - 1
    ! Receive number of points and first point
    call MPI_RECV(buffer, 2, MPI_INTEGER, i, E_OUT1, MPI_COMM_WORLD, &
      status, ierr)
    start = buffer(1)
    npts = buffer(2)

    ! Receive results
    call MPI_RECV(results(start),npts,MPI_DOUBLE_PRECISION, i, E_OUT2, &
      MPI_COMM_WORLD, status, ierr)
  end do

  ! Store master's results in results array
  do i = first, first+npoints-1
    results(i) = values(i)
  end do

  ! Print results
  print *,'Check final results...'
  do i=0, 9
     write (6,'(f6.3," ",$)') results((npoints * i)/10)
  end do
  print *, ''

end subroutine out_master

subroutine out_workers
  !---------------------------------------------------------------------
  ! Send the updated values to the master
  !---------------------------------------------------------------------
  
  use mod1, only : &
    values, oldval, newval, first, npoints
    
  use mpi, only : &
    MPI_DOUBLE_PRECISION, MPI_INTEGER, MPI_COMM_WORLD
  
  implicit none

  integer :: buffer(2), nbuf(4)
  integer :: ierr

  ! Send first point and number of points handled to master
  buffer(1) = first
  buffer(2) = npoints
  ierr = 0
  call MPI_SEND(buffer,2,MPI_INTEGER,MASTER,E_OUT1, &
    MPI_COMM_WORLD,ierr )

  ! Send results to master
  call MPI_SEND(values(1),npoints,MPI_DOUBLE_PRECISION,MASTER, &
    E_OUT2,MPI_COMM_WORLD,ierr )

end subroutine out_workers

end module wave

program wave_send

  use mpi, only : MPI_COMM_WORLD
    
  use mod1, only : &
    taskid, numtasks
     
  use wave, only : &
    init_master, init_workers, init_line, out_master, out_workers, &
    MASTER
    
  implicit none
    
  integer :: ierr
  integer :: left, right, nbuf(4)

  ! Determine number of tasks and taskid
  call MPI_INIT(ierr)
  call MPI_COMM_RANK(MPI_COMM_WORLD, taskid, ierr)
  call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)

  ! Determine left and right neighbors
  if (taskid == numtasks-1) then
    right = 0
  else 
    right = taskid + 1
  end if

  if (taskid == 0) then
    left = numtasks - 1
  else 
    left = taskid - 1
  end if

  ! Get program parameters and initialize wave values
  if (taskid == MASTER) then
    call init_master
  else
    call init_workers
  end if
  call init_line

  ! Update values along the wave for nstep time steps
  call update(left, right)

  ! Master collects results from workers and prints
  if (taskid == MASTER) then
    call out_master
  else 
    call out_workers
  end if
  if (taskid == MASTER) print *,"wave finished"
  call MPI_FINALIZE(ierr)

contains
  
  subroutine update(left, right)
    !---------------------------------------------------------------------
    ! Update all values along line a specified number of times 
    !---------------------------------------------------------------------
    
    use mpi, only : &
      MPI_WTIME, MPI_STATUS_SIZE, MPI_LOGICAL, MPI_DOUBLE_PRECISION, MPI_COMM_WORLD
    
    use mod1, only : &
      taskid, numtasks, tpoints, nsteps, npoints, first,values, oldval, &
      newval
    
    use wave, only : &
      MASTER, DURATION
    
    implicit none
    
    integer :: left, right
    
    integer, parameter :: E_RtoL = 10
    integer, parameter :: E_LtoR = 20
    integer :: status(MPI_STATUS_SIZE), ierr
    integer :: i, j, id_rtol, id_ltor, iterations
    real*8 :: dtime, c, dx, tau, sqtau, time_start, time_end
    logical :: finished
  
    iterations = 0
    dtime = 0.3
    c = 1.0
    dx = 1.0
    tau = (c * dtime / dx)
    sqtau = tau * tau
    time_start = MPI_WTIME()
    do
      time_end = MPI_WTIME()
      finished = .FALSE.
      if (taskid == MASTER) then
        if (time_end - time_start >= DURATION) then
          finished = .TRUE.
        end if
      end if
      call MPI_BCAST(finished, 1, MPI_LOGICAL, MASTER, MPI_COMM_WORLD, &
        ierr)
      if (finished) exit
  
      ! Update values for each point along string
      do i = 1, 100
        iterations = iterations + 1
        ! Exchange data with "left-hand" neighbor
        if (first /= 1) then
          call MPI_SEND(values(1),1,MPI_DOUBLE_PRECISION,left, &
            E_RtoL,MPI_COMM_WORLD,ierr)
          call MPI_RECV( values(0),1,MPI_DOUBLE_PRECISION,left, &
            E_LtoR, MPI_COMM_WORLD, status, ierr)
        end if
        ! Exchange data with "right-hand" neighbor
        if (first+npoints-1 /= tpoints) then
          call MPI_SEND(values(npoints),1,MPI_DOUBLE_PRECISION, &
            right,E_LtoR,MPI_COMM_WORLD,ierr)
          call MPI_RECV(values(npoints+1), 1, MPI_DOUBLE_PRECISION, &
            right,E_RtoL, MPI_COMM_WORLD, status, ierr)
        end if
  
        ! Update points along line
        do j = 1, npoints
          ! Global endpoints
          if ((first+j-1 == 1) .or. (first+j-1 == tpoints)) then
            newval(j) = 0.0
          else
            ! Use wave equation to update points
            newval(j) = (2.0 * values(j)) - oldval(j)   &
            + (sqtau * (values(j-1) - (2.0 * values(j)) &
            + values(j+1)))
          end if
        end do
  
        do j = 1, npoints
          oldval(j) = values(j)
          values(j) = newval(j)
        end do
      end do
    end do
    if (first == 1) then
      print *, iterations, " iterations completed"
    end if
  end subroutine update

end program wave_send
