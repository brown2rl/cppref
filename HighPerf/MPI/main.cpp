#include <vector>
#include <stack>

using namespace std;

int main()
{
  MPI_Init();
 
  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0)
  {
    cout << "number " << endl;
    int n;
    cin >> n;
    for (size_t i = 1; i < size; i++)
    {
      MPI_Send(&n, 1, MPI_INT, i , 0, MPI_COMM_WORLD);
    }
  else {
      int n;
      MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      cout << n << " ^ " << rank << " = " << pow(n, rank) << endl;
  }

  MPI_Finalize();
 return 0;
}
