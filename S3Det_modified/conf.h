
//Conf for local
//Directory where temporary files created during the execution of S3det program will be hosted. Caution: keep this directory alive.
	string tmp_directory="/tmp/";
//Directory where S3det_Wilcoxon_test.R file is hosted
	string exec_directory="./";
//Path for calling R from the S3det program
//	string order="/opt/R/R-2.13/lib64/R/bin/R";
	string order="/usr/bin/R";


//--------------------------------------------------------------------------------
string parameter_list_for_Treedet_Server="NO";
//Conf for Treedet server
// 	string parameter_list_for_Treedet_Server="YES";
// 	string tmp_directory="/tmp/";
// 	string exec_directory="/gpfs_home/treedet/SoftTreedetV3/LIB/Methods/S3DET/";
// 	string order="/gpfs_home/soft/intel/R/bin/R";
// 	string parameter_list_for_Treedet_Server="YES";