# Zia

Final year projet
Zia in CPP

Subject:

The goal of the Zia project is to create an HTTP server. This server will be able to serve typical HTTP doc-uments and page requests, as well as CGI execution and more. The serverMUSTbe written in C++, with support for interoperable modules.

TheZiaproject is split into 3 big steps:
•The creation of the API
•The local API election
•The implementation/creation of all the modules
These items will all be discussed in details below

YourZia MUSTcompile and run on at least oneWindowsdistributionANDoneUnixdistribution.ItMUSTbe built using a [CMake] and dependenciesMUSTbe handled using [conan].These, and only these, conan repositories may be used:

•conan-center:https://bintray.com/conan/conan-center

•epitech:https://bintray.com/epitech/public-conan

•bincrafters:https://bintray.com/bincrafters/public-conan

The build of your project will be done in the following fashion (for Unix systems):∇Terminal-  +x∼/B-CPP-510> mkdir build && cd build && conan install .. --build=missing && cmake.. -G “Unix Makefiles” && cmake --build .
