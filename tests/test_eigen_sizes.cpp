#include "hdf5.hpp"

#include <gtest/gtest.h>

#include <iostream>

// File Testing
TEST(TestFDCLUAVFile, Eigen3by1) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    Eigen::Matrix<double, 3, 1> mat, mat_read;
    mat = Eigen::MatrixXd::Random(3, 1);
    hf_file.write("matrix", mat);
    
    hf_file.read("matrix", mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}

TEST(TestFDCLUAVFile, Eigen3by3) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    Eigen::Matrix<double, 3, 3> mat, mat_read;
    mat = Eigen::MatrixXd::Random(3, 3);
    hf_file.write("matrix", mat);
    
    hf_file.read("matrix", mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}

TEST(TestFDCLUAVFile, Eigen4by1) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    Eigen::Matrix<double, 4, 1> mat, mat_read;
    mat = Eigen::MatrixXd::Random(4, 1);
    hf_file.write("matrix", mat);
    
    hf_file.read("matrix", mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}

// Group testing
TEST(TestFDCLUAVGroup, Eigen3by1) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    HDF5::Group hf_group = hf_file.group("data");
    Eigen::Matrix<double, 3, 1> mat, mat_read;
    mat = Eigen::MatrixXd::Random(3, 1);
    hf_group.write("matrix", mat);
    
    hf_group.read("matrix", mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}

TEST(TestFDCLUAVGroup, Eigen3by3) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    HDF5::Group hf_group = hf_file.group("data");
    Eigen::Matrix<double, 3, 3> mat, mat_read;
    mat = Eigen::MatrixXd::Random(3, 3);
    hf_group.write("matrix", mat);
    
    hf_group.read("matrix", mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}

TEST(TestFDCLUAVGroup, Eigen4by1) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    HDF5::Group hf_group = hf_file.group("data");
    Eigen::Matrix<double, 4, 1> mat, mat_read;
    mat = Eigen::MatrixXd::Random(4, 1);
    hf_group.write("matrix", mat);
    
    hf_group.read("matrix", mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}

// Dataset Testing
TEST(TestFDCLUAVDataSet, Eigen3by1) {
    HDF5::File hf_file("/tmp/test.hdf5", HDF5::File::Truncate);
    Eigen::Matrix<double, 3, 1> mat, mat_read;
    mat = Eigen::MatrixXd::Random(3, 1);

    HDF5::DataSet hf_dataset = hf_file.dataset("matrix", mat);
    
    hf_dataset.read( mat_read);

    ASSERT_TRUE(mat_read.isApprox(mat));
}
