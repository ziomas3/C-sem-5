// Author: Wes Kendall
// Modified by: Zbigniew Koza
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // Inicjalizacja środowiska MPI
  MPI_Init(NULL, NULL);
  int world_rank, world_size; // id procesu; liczba procesów
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); 
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  if (world_size < 2) // Muszą istnieć co najmniej dwa procesy  
  {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int number = 189;
  if (world_rank == 0) 
  {
    // Jeżeli proces ma rank 0, to wysyła liczbę -1 do procesu 1  (tag == 1 - deadlock!)
    number = -1;
    printf("Process 0 is sending an int of value %d\n", number);
    MPI_Send(&number, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
  } 
  else if (world_rank == 1) 
  {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  MPI_Finalize();
}

