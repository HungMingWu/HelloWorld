PROJECT(NetworkLibrary)
SET (SRC_PATH gethostbyname.c socket.c)
ADD_EXECUTABLE(bin/gethostbyname ${SRC_PATH})
