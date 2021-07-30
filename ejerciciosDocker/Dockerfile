FROM centos:7
RUN yum install -y gcc-c++
COPY example.cpp /
RUN g++ /example.cpp
ENTRYPOINT [ "/a.out" ]
