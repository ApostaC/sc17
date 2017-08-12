all: kmeans

kmeans: kmeans.upc
	upcc -tv $< -o $@

clean:
	-rm -f kmeans
