mkdir build && cd build
case "$1" in
-h) cmake -DBUILD_SHARED_LIBS=ON .. ;;
-t) cmake -DBUILD_SHARED_LIBS=OFF .. ;;
*) cmake ..;;
esac
make
cd logger_app && touch log.txt