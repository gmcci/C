savedcmd_led.ko := ld -r -m elf_x86_64 -z noexecstack --no-warn-rwx-segments --build-id=sha1  -T /usr/lib/modules/6.18.2-1-MANJARO/build/scripts/module.lds -o led.ko led.o led.mod.o .module-common.o
