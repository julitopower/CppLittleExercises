#include <iostream>
#include <jit/jit.h>

/*! \brief Short example of the usage of Libjit
 *
 * In this example we dynamically define a function
 * fn(int a, int b, int c) = a * b * c
 */
int main(int argc, char *argv[])
{
  jit_context_t ctx = jit_context_create();
  jit_context_build_start(ctx);

  // Let's create a function
  jit_type_t params[3];
  jit_type_t signature;
  params[0] = jit_type_int;
  params[1] = jit_type_int;
  params[2] = jit_type_int;

  signature = jit_type_create_signature(jit_abi_cdecl, jit_type_int, params, 3, 1);
  jit_function_t fn = jit_function_create(ctx, signature);

  // Now we can define the body of the function
  // First get hold of the arguments
  jit_value_t x, y, z;
  x = jit_value_get_param(fn, 0);
  y = jit_value_get_param(fn, 1);
  z = jit_value_get_param(fn, 2);

  jit_value_t temp1, temp2;
  temp1 = jit_insn_mul(fn, x, y);
  temp2 = jit_insn_mul(fn, temp1, z);
  jit_insn_return(fn, temp2);

  // Compile the function and unlock the context
  jit_function_compile(fn);
  jit_context_build_end(ctx);

  // Now let's call our function
  jit_int  arg1, arg2, arg3;
  void* args[3];
  jit_int result;

  arg1 = 3;
  arg2 = 5;
  arg3 = 2;
  args[0] = &arg1;
  args[1] = &arg2;
  args[2] = &arg3;
  jit_function_apply(fn, args, &result);
  std::cout << static_cast<int>(result) << std::endl;

  jit_context_destroy(ctx);
  return 0;
}
