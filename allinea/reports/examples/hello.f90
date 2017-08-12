INTEGER FUNCTION FUNC1 ()
  INTEGER :: my_int, your_int
  my_int=2
  your_int=3
  FUNC1=my_int*your_int
END
        
SUBROUTINE SUB1 ()
  INTEGER :: test,FUNC1
  test=FUNC1()
  IF (test.eq.1) THEN
    test=0
  ELSE
    test=-1
  END IF
END
   
PROGRAM hellof90
include 'mpif.h'
      
INTEGER :: i,my_rank,p,source,dest,tag,x,y,beingwatched,ierr,size
CHARACTER :: message*21
CHARACTER :: messagefirst
integer, dimension(:), allocatable :: someints

INTEGER :: status(MPI_STATUS_SIZE)
       
CALL MPI_INIT(ierr)
CALL MPI_COMM_SIZE(MPI_COMM_WORLD, size, ierr)
CALL MPI_COMM_RANK(MPI_COMM_WORLD, my_rank, ierr)
       
IF (size.eq.8) THEN
   IF (my_rank.eq.5) THEN
     CALL MPI_SEND(message,400,MPI_CHARACTER,dest,tag,MPI_COMM_WORLD,ierr)
   END IF
END IF
  
       
PRINT *,"My rank is ",my_rank,"!"
      
CALL SUB1()
      
beingwatched=1
tag=0

allocate(someints(100))
       
IF (my_rank.ne.0) THEN
  PRINT *,"Greetings from process ",my_rank,"!"
  PRINT *,"Sending message from ",my_rank,"!"
  dest=0
  CALL MPI_Send(message,21,MPI_CHARACTER,dest,tag,MPI_COMM_WORLD,ierr)
  beingwatched=beingwatched-1
ELSE
  message="Hello from my process"
  DO source=1,(size-1)
    PRINT *,"waiting for message from ",source
    CALL MPI_Recv(message,21,MPI_CHARACTER,source,tag,MPI_COMM_WORLD,status,ierr)
    PRINT *,"Message recieved: ",message
    beingwatched=beingwatched+1
  END DO
END IF
       
beingwatched=12
CALL MPI_Finalize(ierr)
beingwatched=0
PRINT *,"All done...",my_rank
END
