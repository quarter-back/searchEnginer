#include "pageLib.hh"

int main() {
    string path = "../yuliao";
    DirScanner dirScanner;
    dirScanner.traverse(path);


    PageLib pl(dirScanner);
    pl.create();
    pl.offset();
    pl.store();
    return 0;
}
