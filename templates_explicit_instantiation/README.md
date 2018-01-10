# C++ explicit template instantiation

This projects demonstrates how to use C++ templates explicitn instantiation. This mechanims can be used to reduce the ammount of code in header files that consumers of the template bring upon including the template declaraion header file. This technique introduces its own problems.

The teamplate is declared in __template.hpp__. The template is defined in __template_def.hpp__. Finally the explicit instatiation takes place in template_inst.cpp.

Notice how __main.cpp__ only nees to include the template declararion header, avoiding the overhead of including the definition as well.