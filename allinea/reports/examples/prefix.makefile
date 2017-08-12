####### Definitions

nvccflags = -g -G
lflags = 
target = prefix

####### Target
all: $(target)

$(target) : prefix.cu
	nvcc $(nvccflags) -o $(target) prefix.cu


####### Clean

.PHONY : clean
clean :
	-rm -f $(target) core

