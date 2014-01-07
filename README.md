fasta_io
=======

Read bio sequence from fasta file

Build Test
----------
    cd fasta_io/
    g++ src/fasta_io/fasta_*.cpp test/fasta_io/fasta_*.cpp -lgtest -lgtest_main -lpthread
    ./fasta_io_test
