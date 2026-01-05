savedcmd_heart.mod := printf '%s\n'   heart.o | awk '!x[$$0]++ { print("./"$$0) }' > heart.mod
