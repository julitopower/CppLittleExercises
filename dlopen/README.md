# dlopen and rpath

This example shows how to use dlopen to dynamically load a shared object and access a symbol in it. This is the way pluggins are usually handled.

The main application dynamically loads l2, which depends on l1. In order for the loader to find l1 when l2 is loaded, we set the RPATH using CMake. The RPATH is set to be relative to l2.

# References

* [dlopen](http://man7.org/linux/man-pages/man3/dlopen.3.html)
* [RPATH](https://en.wikipedia.org/wiki/Rpath)
* [Cmake and RPATH](https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/RPATH-handling)
