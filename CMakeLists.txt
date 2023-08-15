# CMakeのバージョンを設定
cmake_minimum_required(VERSION 0.01)
# プロジェクト名と使用する言語を設定
project(pathGenerate CXX)
# a.outという実行ファイルをmain.cppとhello.cppから作成
add_executable(pathGenerater main.cpp points.cpp)
