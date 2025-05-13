#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void round_robin(int rank, int num_procs) {
    long int rand_mine, rand_prev;
    int rank_next = (rank + 1) % num_procs;
    int rank_prev = rank == 0 ? num_procs - 1 : rank - 1;
    MPI_Status status;

    // generate a random number (Windows compatible)
    srand((unsigned int)(time(NULL) + rank));
    rand_mine = rand() % 100;
    printf("%d: random value  %ld\n", rank, rand_mine);
    fflush(stdout);

    if (rank % 2 == 0) { // if rank even
        printf("%d: sending %ld to %d\n", rank, rand_mine, rank_next);
        fflush(stdout);
        MPI_Send((void *)&rand_mine, 1, MPI_LONG, rank_next, 1, MPI_COMM_WORLD);

        MPI_Recv((void *)&rand_prev, 1, MPI_LONG, rank_prev, 1, MPI_COMM_WORLD, &status);
        printf("%d: received %ld from %d\n", rank, rand_prev, rank_prev);
        fflush(stdout);
    } else { // if rank odd
        MPI_Recv((void *)&rand_prev, 1, MPI_LONG, rank_prev, 1, MPI_COMM_WORLD, &status);
        printf("%d: received %ld from %d\n", rank, rand_prev, rank_prev);
        fflush(stdout);

        printf("%d: sending %ld to %d\n", rank, rand_prev, rank_next);
        fflush(stdout);
        MPI_Send((void *)&rand_prev, 1, MPI_LONG, rank_next, 1, MPI_COMM_WORLD);
    }
}

int main (int argc, char **argv) {
    int num_procs;
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Hello from process %d of %d processes\n", rank, num_procs);
    fflush(stdout);
    round_robin(rank, num_procs);
    printf("Goodbye from process %d of %d processes\n", rank, num_procs);
    fflush(stdout);
    MPI_Finalize();
}