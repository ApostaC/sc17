__kernel void matrixMulVector2D(__global const int * matrix,
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

__kernel void matrixMulVector1D(__global const int * matrix,
										 __global const int * v,
										 __global int * ans,
										 const int row,
										 const int col)
{
	const int i = get_global_id(0);
	if(i<row)
	{
		for(int j=0;j<col;j++)
		{
			ans[i]+=matrix[i*col+j]*v[j];
		}
	}
}
