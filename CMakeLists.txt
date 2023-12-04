# 设置项目名称和版本
cmake_minimum_required(VERSION 3.25)
# 设置项目名称和版本
project(MyProject)

#设置cpp版本
set(CMAKE_C_STANDARD 17)

# 定义一个函数来递归查找子目录下的.cpp文件并生成可执行程序
function(add_subdirectories_recursive dir)
  # 获取当前目录下的所有子目录
  file(GLOB SUBDIRECTORIES RELATIVE ${dir} ${dir}/*)

  # 遍历每个子目录
  foreach(subdir ${SUBDIRECTORIES})
    # 检查子目录是否为目录
    if(IS_DIRECTORY ${dir}/${subdir})
      # 添加子目录下的所有源文件
      file(GLOB SOURCES "${dir}/${subdir}/*.c")

      # 检查是否存在源文件
      if(SOURCES)
        # 编译子目录下的源文件为一个可执行程序
        add_executable(${subdir} ${SOURCES})
      endif()
      
      # 递归调用该函数，处理子目录中的子目录
      add_subdirectories_recursive(${dir}/${subdir})
    endif()
  endforeach()
endfunction()

# 调用函数来处理项目根目录下的子目录
add_subdirectories_recursive(${CMAKE_CURRENT_SOURCE_DIR})

