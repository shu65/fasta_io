/*
 * fasta_io_test.cpp
 *
 *   Copyright (c) 2013, Shuji Suzuki
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above Copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above Copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of the authors nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *   PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include "../src/fasta_io.hpp"

using namespace std;

TEST(FastaIoTest, ReadRecode) {
  ifstream in("./test/test_dna.fa");
  ASSERT_TRUE(in);
  string header;
  string sequence;
  int ret = 0;
  ret = fast_io::ReadRecode(in, header, sequence);
  EXPECT_EQ(0, ret);
  EXPECT_EQ("test0", header);
  EXPECT_EQ("AGCGAGAGCGAGTGGTGGGCAAAAAAACCTATACTGCAAAATTTTATGAAAGGTGCTTATTGTCCTCTGAATGAT",
      sequence);

  ret = fast_io::ReadRecode(in, header, sequence);
  EXPECT_EQ(0, ret);
  EXPECT_EQ("test1 is added A at forward oftest1 ", header);
  EXPECT_EQ("AAGCGAGAGCGAGTGGTGGGCAAAAAAACCTATACTGCAAAATTTTATGAAAGGTGCTTATTGTCCTCTGAATGA",
      sequence);

  ret = fast_io::ReadRecode(in, header, sequence);
  EXPECT_EQ(0, ret);
  EXPECT_EQ("test5", header);
  EXPECT_EQ("GCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCT",
      sequence);

  ret = fast_io::ReadRecode(in, header, sequence);
  EXPECT_EQ(0, ret);
  EXPECT_EQ("test6", header);
  EXPECT_EQ("GCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTGCTATGAAAGGTGCTTATTGTCCTCTGAATGAT",
      sequence);

  ret = fast_io::ReadRecode(in, header, sequence);
  EXPECT_EQ(0, ret);
  EXPECT_EQ("test7 reverse complementary strand of test6", header);
  EXPECT_EQ("ATCATTCAGAGGACAATAAGCACCTTTCATAGCAGCAGCAGCAGCAGCAGCAGCAGCAGCAGCAGCAGCAGCAGC",
      sequence);

  ret = fast_io::ReadRecode(in, header, sequence);
  EXPECT_NE(0, ret);
}

