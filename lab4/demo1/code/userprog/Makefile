# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the multiprogramming assignment
#    Defines set up assuming multiprogramming is done before the file system.
#    If not, use the "filesys first"  defines below. 
#
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB
INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H)
CFILES = $(THREAD_C) $(USERPROG_C)
C_OFILES = $(THREAD_O) $(USERPROG_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS
# INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/system.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../userprog/memorymanager.h \
  ../userprog/bitmap.h ../threads/utility.h ../filesys/openfile.h \
  ../userprog/processmanager.h ../userprog/syscall.h ../threads/thread.h \
  ../threads/Table.h ../threads/synch-sleep.h ../filesys/filesys.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
  ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/system.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/utility.h \
  ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
  ../threads/thread.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../machine/machine.h \
  ../threads/utility.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../threads/list.h ../threads/system.h ../threads/scheduler.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
  ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/synch.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
synch-sleep.o: ../threads/synch-sleep.cc ../threads/copyright.h \
  ../threads/synch-sleep.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/system.h ../threads/scheduler.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../filesys/filesys.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../machine/machine.h \
  ../threads/utility.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../threads/switch.h ../threads/synch.h ../threads/list.h \
  ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/utility.h \
  ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
Table.o: ../threads/Table.cc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ios \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iosfwd \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++locale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstring \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstddef \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdio \
  /usr/include/stdio.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++io.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/sched.h /usr/include/bits/time.h \
  /usr/include/signal.h /usr/include/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cctype \
  /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stringfwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/postypes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/functexcept.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/char_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algobase.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/climits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_pair.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/concept_check.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/debug/debug.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/localefwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ios_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/atomicity.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/atomic_word.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_classes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/string \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/memory \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ext/mt_allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/new \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_construct.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/limits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_function.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/algorithm \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algo.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_heap.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/streambuf \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_inline.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/codecvt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/time_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/messages_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ostream.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/locale \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/typeinfo \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/istream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/istream.tcc \
  ../threads/Table.h ../threads/synch-sleep.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
  ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/system.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h /usr/include/signal.h \
  /usr/include/bits/sigset.h /usr/include/bits/signum.h \
  /usr/include/time.h /usr/include/bits/siginfo.h \
  /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
  /usr/include/asm/sigcontext.h /usr/include/bits/sigstack.h \
  /usr/include/sys/ucontext.h /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sigthread.h /usr/include/sys/types.h \
  /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/sys/time.h /usr/include/sys/socket.h \
  /usr/include/sys/uio.h /usr/include/bits/uio.h \
  /usr/include/bits/socket.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/sys/file.h /usr/include/fcntl.h \
  /usr/include/bits/fcntl.h /usr/include/sys/stat.h \
  /usr/include/bits/stat.h /usr/include/sys/un.h /usr/include/sys/mman.h \
  /usr/include/bits/mman.h /usr/include/unistd.h \
  /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
  /usr/include/bits/confname.h /usr/include/getopt.h /usr/include/errno.h \
  /usr/include/bits/errno.h /usr/include/linux/errno.h \
  /usr/include/asm/errno.h ../machine/interrupt.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/system.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/utility.h \
  ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
  ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h \
  /usr/include/bits/wordsize.h /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../machine/machine.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../userprog/memorymanager.h \
  ../userprog/bitmap.h ../threads/utility.h ../filesys/openfile.h \
  ../userprog/processmanager.h ../userprog/syscall.h ../threads/thread.h \
  ../threads/Table.h ../threads/synch-sleep.h ../filesys/filesys.h
addrspace.o: ../userprog/addrspace.cc ../threads/copyright.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ios \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iosfwd \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++locale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstring \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstddef \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdio \
  /usr/include/stdio.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++io.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/sched.h /usr/include/bits/time.h \
  /usr/include/signal.h /usr/include/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cctype \
  /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stringfwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/postypes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/functexcept.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/char_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algobase.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/climits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_pair.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/concept_check.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/debug/debug.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/localefwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ios_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/atomicity.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/atomic_word.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_classes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/string \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/memory \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ext/mt_allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/new \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_construct.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/limits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_function.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/algorithm \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algo.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_heap.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/streambuf \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_inline.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/codecvt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/time_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/messages_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ostream.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/locale \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/typeinfo \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/istream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/istream.tcc \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h ../userprog/addrspace.h \
  ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc ../threads/copyright.h \
  ../userprog/bitmap.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../filesys/openfile.h \
  ../threads/copyright.h ../threads/utility.h
memorymanager.o: ../userprog/memorymanager.cc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ios \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iosfwd \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++locale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstring \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstddef \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdio \
  /usr/include/stdio.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++io.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/sched.h /usr/include/bits/time.h \
  /usr/include/signal.h /usr/include/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cctype \
  /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stringfwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/postypes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/functexcept.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/char_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algobase.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/climits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_pair.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/concept_check.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/debug/debug.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/localefwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ios_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/atomicity.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/atomic_word.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_classes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/string \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/memory \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ext/mt_allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/new \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_construct.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/limits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_function.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/algorithm \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algo.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_heap.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/streambuf \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_inline.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/codecvt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/time_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/messages_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ostream.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/locale \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/typeinfo \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/istream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/istream.tcc \
  ../machine/machine.h ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
  ../machine/translate.h ../machine/disk.h ../userprog/memorymanager.h \
  ../userprog/bitmap.h ../threads/copyright.h ../threads/utility.h \
  ../filesys/openfile.h ../threads/copyright.h ../threads/utility.h
processmanager.o: ../userprog/processmanager.cc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ios \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iosfwd \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++locale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstring \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstddef \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdio \
  /usr/include/stdio.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++io.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/sched.h /usr/include/bits/time.h \
  /usr/include/signal.h /usr/include/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cctype \
  /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stringfwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/postypes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/functexcept.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/char_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algobase.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/climits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_pair.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/concept_check.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/debug/debug.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/localefwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ios_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/atomicity.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/atomic_word.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_classes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/string \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/memory \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ext/mt_allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/new \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_construct.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/limits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_function.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/algorithm \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algo.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_heap.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/streambuf \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_inline.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/codecvt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/time_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/messages_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ostream.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/locale \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/typeinfo \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/istream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/istream.tcc \
  ../userprog/processmanager.h ../userprog/syscall.h \
  ../threads/copyright.h ../threads/thread.h ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/Table.h ../threads/synch-sleep.h \
  ../threads/list.h ../threads/thread.h ../threads/system.h \
  ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../userprog/memorymanager.h \
  ../userprog/bitmap.h ../threads/utility.h ../filesys/openfile.h \
  ../userprog/processmanager.h ../filesys/filesys.h
exception.o: ../userprog/exception.cc ../threads/copyright.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/os_defines.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ostream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ios \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/iosfwd \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++locale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstring \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstddef \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/string.h /usr/include/xlocale.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdio \
  /usr/include/stdio.h /usr/include/bits/types.h \
  /usr/include/bits/typesizes.h /usr/include/libio.h \
  /usr/include/_G_config.h /usr/include/wchar.h /usr/include/bits/wchar.h \
  /usr/include/gconv.h ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/clocale \
  /usr/include/locale.h /usr/include/bits/locale.h \
  /usr/include/langinfo.h /usr/include/nl_types.h /usr/include/iconv.h \
  /usr/include/libintl.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++io.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
  /usr/include/bits/sched.h /usr/include/bits/time.h \
  /usr/include/signal.h /usr/include/bits/sigset.h \
  /usr/include/bits/pthreadtypes.h /usr/include/bits/setjmp.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cctype \
  /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stringfwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/postypes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ctime \
  /usr/include/stdint.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/functexcept.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/exception \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/char_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algobase.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/climits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cstdlib \
  /usr/include/stdlib.h /usr/include/bits/waitflags.h \
  /usr/include/bits/waitstatus.h /usr/include/sys/types.h \
  /usr/include/sys/select.h /usr/include/bits/select.h \
  /usr/include/sys/sysmacros.h /usr/include/alloca.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_pair.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/cpp_type_traits.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/concept_check.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/debug/debug.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/localefwd.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ios_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/atomicity.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/atomic_word.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_classes.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/string \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/memory \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/c++allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/ext/mt_allocator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/new \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_construct.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_uninitialized.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/limits \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_function.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/algorithm \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_algo.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_heap.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/stl_tempbuf.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_string.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/streambuf \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/streambuf_iterator.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_base.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/ctype_inline.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/codecvt.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/time_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/i386-redhat-linux/bits/messages_members.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/basic_ios.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/ostream.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/locale \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/locale_facets.tcc \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/typeinfo \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/istream \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/../../../../include/c++/4.0.2/bits/istream.tcc \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  ../threads/thread.h ../machine/machine.h ../threads/utility.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../userprog/memorymanager.h ../userprog/bitmap.h \
  ../threads/utility.h ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
progtest.o: ../userprog/progtest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/thread.h \
  ../machine/machine.h ../threads/utility.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/utility.h \
  ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h ../machine/console.h \
  ../userprog/addrspace.h ../threads/synch.h
console.o: ../machine/console.cc ../threads/copyright.h \
  ../machine/console.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../machine/machine.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../userprog/memorymanager.h \
  ../userprog/bitmap.h ../threads/utility.h ../filesys/openfile.h \
  ../userprog/processmanager.h ../userprog/syscall.h ../threads/thread.h \
  ../threads/Table.h ../threads/synch-sleep.h ../filesys/filesys.h
machine.o: ../machine/machine.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../machine/translate.h \
  ../machine/disk.h ../threads/system.h ../threads/utility.h \
  ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
  ../threads/copyright.h ../filesys/filesys.h ../threads/copyright.h \
  ../filesys/openfile.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../userprog/memorymanager.h \
  ../userprog/bitmap.h ../threads/utility.h ../filesys/openfile.h \
  ../userprog/processmanager.h ../userprog/syscall.h ../threads/thread.h \
  ../threads/Table.h ../threads/synch-sleep.h ../filesys/filesys.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../machine/translate.h \
  ../machine/disk.h ../machine/mipssim.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../machine/machine.h \
  ../userprog/addrspace.h ../threads/copyright.h ../filesys/filesys.h \
  ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/utility.h \
  ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
translate.o: ../machine/translate.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
  ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/include/gnu/stubs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs-32.h \
  /usr/lib/gcc/i386-redhat-linux/4.0.2/include/stddef.h \
  /usr/include/bits/types.h /usr/include/bits/typesizes.h \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
  /usr/include/bits/wchar.h /usr/include/gconv.h ../threads/stdarg.h \
  /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
  /usr/include/string.h /usr/include/xlocale.h ../machine/translate.h \
  ../machine/disk.h ../userprog/addrspace.h ../threads/copyright.h \
  ../filesys/filesys.h ../threads/copyright.h ../filesys/openfile.h \
  ../threads/utility.h ../threads/system.h ../threads/utility.h \
  ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/utility.h \
  ../filesys/openfile.h ../userprog/processmanager.h \
  ../userprog/syscall.h ../threads/thread.h ../threads/Table.h \
  ../threads/synch-sleep.h ../filesys/filesys.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
