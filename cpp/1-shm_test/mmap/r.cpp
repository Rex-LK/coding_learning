#include <iostream>
#include <string>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
using namespace std;
struct MyData
{
    char name[20];
    int age;
    vector<int> v;
};

void readMemory()
{
    // specify shared file path
    char *shared_file_name = "/tmp/shm";

    // open mmap file
    int fd = open(shared_file_name, O_RDONLY, 00777);
    if (fd < 0)
        cout << "open file error" << endl;

    const unsigned long buff_size = 4096;
    // size_t read_size = buff_size;
    size_t read_size = sizeof(MyData);

    // map file to memory
    void *p = mmap(NULL, read_size, PROT_READ, MAP_SHARED, fd, 0);

    cout << "read shared data: " << endl;

    //    char *share_buffer = (char *)p;
    //    cout << share_buffer << endl;
    MyData *share_buffer = (MyData *)p;
    string a = share_buffer->name;

    cout << share_buffer->name << " " << share_buffer->age << endl;
    cout << share_buffer->v.size() << endl;

    // unmap and close
    munmap(p, read_size);
    close(fd);
}

int main()
{
    readMemory();

    // getchar();

    return 0;
}
