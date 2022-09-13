
# GCC compilation options

opts=""
opts="${opts} -Wbad-function-cast -Wmissing-declarations -Wmissing-parameter-type -Wmissing-prototypes -Wnested-externs"
opts="${opts} -Wstrict-prototypes -Wdeclaration-after-statement -Wpointer-sign -ansi -pedantic"
opts="${opts} -Wall -Wextra -Werror"

opts_dbg="-DDEBUG -o0"
opts_rel="-DNDEBUG -o2"
