program serial

  implicit none
  integer, parameter :: loops = 1000000000

  call fusion
  call unrolling
  call stride
  call power
  call lookup

  print *,"serial finished"

contains

subroutine fusion

  implicit none
  integer, parameter :: xy=1000000
  real (kind=8) :: x(xy), y(xy)
  real :: alpha,dot
  integer i,j

  alpha=3.3
  x=4.4
  y=5.5
  dot=0.0
  do j=1,500
    do i = 1,xy
      y(i) = y(i) + alpha*x(i)
    end do
    do i = 1, xy
      dot = dot + y(i)*y(i)
    end do
    do i = 1,xy
      y(i) = y(i) + alpha*x(i)
      dot = dot + y(i)*y(i)
    end do
  end do

  print *,"fusion answer", dot

end subroutine fusion

subroutine unrolling

  implicit none
  integer, parameter :: lda=1000
  integer, parameter :: ldb=1000
  integer, parameter :: ldc=1000
  integer, parameter :: l=1000
  integer, parameter :: m=1000
  integer, parameter :: n=1000
  integer, parameter :: junroll=4
  integer, parameter :: kunroll=4
  integer :: i,j,k

  real (kind=8) :: a(lda,l), b(ldb,n), c(ldc,n) 

  a=1.1
  b=2.2
  c=3.3

  do j = 1, n 
    do k = 1, l 
      do i = 1, n 
        c(i,j) = c(i,j) + a(i,k)*b(k,j) 
      end do 
    end do 
  end do 

  do j = 1, n, junroll
    do k = 1, l 
      do i = 1, n 
        c(i,j+0) = c(i,j+0) + a(i,k)*b(k,j+0) 
        c(i,j+1) = c(i,j+1) + a(i,k)*b(k,j+1)  
        c(i,j+2) = c(i,j+2) + a(i,k)*b(k,j+2)  
        c(i,j+3) = c(i,j+3) + a(i,k)*b(k,j+3)  
      end do 
    end do 
  end do 
 
  do j = 1, n 
    do k = 1, l, kunroll
      do i = 1, n  
        c(i,j) = c(i,j) + a(i,k+0)*b(k+0,j) 
        c(i,j) = c(i,j) + a(i,k+1)*b(k+1,j) 
        c(i,j) = c(i,j) + a(i,k+2)*b(k+2,j) 
        c(i,j) = c(i,j) + a(i,k+3)*b(k+3,j) 
      end do 
    end do 
  end do 

  do j = 1, n, junroll
    do k = 1, l, kunroll
      do i = 1, n 
        c(i,j) = c(i,j+0) + a(i,k+0)*b(k+0,j+0) 
        c(i,j) = c(i,j+0) + a(i,k+1)*b(k+1,j+0) 
        c(i,j) = c(i,j+0) + a(i,k+2)*b(k+2,j+0) 
        c(i,j) = c(i,j+0) + a(i,k+3)*b(k+3,j+0) 
        c(i,j) = c(i,j+1) + a(i,k+0)*b(k+0,j+1) 
        c(i,j) = c(i,j+1) + a(i,k+1)*b(k+1,j+1) 
        c(i,j) = c(i,j+1) + a(i,k+2)*b(k+2,j+1) 
        c(i,j) = c(i,j+1) + a(i,k+3)*b(k+3,j+1) 
        c(i,j) = c(i,j+2) + a(i,k+0)*b(k+0,j+2) 
        c(i,j) = c(i,j+2) + a(i,k+1)*b(k+1,j+2) 
        c(i,j) = c(i,j+2) + a(i,k+2)*b(k+2,j+2) 
        c(i,j) = c(i,j+2) + a(i,k+3)*b(k+3,j+2) 
        c(i,j) = c(i,j+3) + a(i,k+0)*b(k+0,j+3) 
        c(i,j) = c(i,j+3) + a(i,k+1)*b(k+1,j+3) 
        c(i,j) = c(i,j+3) + a(i,k+2)*b(k+2,j+3) 
        c(i,j) = c(i,j+3) + a(i,k+3)*b(k+3,j+3) 
      end do 
    end do 
  end do  

  print *,"unrolling answer",sum(c)

end subroutine unrolling

subroutine stride

  implicit none
  real :: a(2000,2000)
  integer :: i,j,l

  do l=1,int(loops/4000000)
    do i=1,2000
      do j=1,2000
        a(i,j)=i*j
      end do
    end do
  end do

  do l=1,int(loops/4000000)
    do j=1,2000
      do i=1,2000
        a(i,j)=i*j
      end do
    end do
  end do

  print *,"stride answer",sum(a)

end subroutine stride

subroutine power

  implicit none
  integer :: i,n
  real :: a,b

  a=1.1
  b=1.1
  do i=1,2*loops
    b=b+(a**4)
  end do

  n=4
  do i=1,2*loops
    b=b-(a**n)
  end do

  do i=1,2*loops
    b=b+(a*a*a*a)
  end do

  print *,"power answer",b

end subroutine power

subroutine lookup

  implicit none
  real (kind=8) :: table1(10),table2(10)
  real (kind=8), parameter :: pi=3.1415926 
  real (kind=8) :: a
  integer :: i
  
  do i=1,10
    table1(i)=pi/i
    table2=cos(table1(i))
  end do
 
  a=1.1 
  do i=1,loops
    a=a+(i*cos(pi/4.0))
  end do

  do i=1,loops
    a=a-(i*cos(table1(4)))
  end do
  
  do i=1,loops
    a=a+(i*table2(4))
  end do

  print *,"lookup answer",a
end subroutine lookup

end program serial
