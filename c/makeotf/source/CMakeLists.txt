add_executable(makeotfexe main.cpp)

target_sources(makeotfexe PRIVATE
    cb.c
    cbpriv.c
    c_main.c
    fcdb.c
    file.c
    mac.c
    makeotflib.h
    cb.h
    cbpriv.h
    fcdb.h
    file.h
    lctype.h
    lerrno.h
    lstdio.h
    lstdlib.h
    lstring.h
    package.h
    systemspecific.h
)

target_link_libraries(makeotfexe PRIVATE ctutil dynarr hotconv makeotf_pstoken typecomp makeotf_cffread m antlr4-runtime)
target_compile_definitions(makeotfexe PRIVATE MAKEOTFLIB_EXPORTS=1)
install(TARGETS makeotfexe DESTINATION bin)


