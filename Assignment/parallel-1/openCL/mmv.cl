__kernel void matrixMulVector(__global const int * matrix,
							  __global const int * v,
							  __global int * ans,
							  const int row,
							  const int col)
{
	const int id_i = get_global_id(0);
	const int id_j = get_global_id(1);
	if(id_i<row && id_j<col)
		ans[id_i]+=matrix[id_i*col+id_j]*v[id_j];

}
__kernel void matrixMulVectorTest(__global const int * matrix,
							  __global const int * v,
							  __global int * ans,
							  const int row,
							  const int col)
{
	const int id_i = get_global_id(0);
	const int id_j = get_global_id(1);
	ans[0]=10;
	ans[1]=1;
}

__kernel void test(__global const int * matrix,
							__global const int * v,
							__global int * ans,
							const int row,
							const int col)
{
ans[0]=10;
}
