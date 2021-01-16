# Requirements

* Flex
* Bison
* libjit, which has to be built from source

## Building libjit

```shell
git clone https://git.savannah.gnu.org/git/libjit.git
cd libjit
./bootstrap
./configure
make -j
make install
```

If you are using a conda environment, and only want to install libjit on it, call ```configure``` as follows:

```shell
./configure --prefix=${conda_root}/envs/${your_env_name}/
```
