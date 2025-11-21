#include <cstdio>
#include <cstdlib>
#include <cstring>

class N {
public:
    virtual void func(N* other) {
        // Example behavior: print our annotation and the "other" object's value
        printf("N::func called: this.annotation=\'%s\' other.value=%d\n", annotation, other->value);
    }

    N(int param) {
        memset(annotation, 0, sizeof(annotation));
        value = param;
    }

    void setAnnotation(char* s) {
        size_t n = strlen(s);
        if (n >= sizeof(annotation)) {
            // mimic original behavior would overflow; here we clamp to avoid UB when running
            n = sizeof(annotation) - 1;
        }
        memcpy(annotation, s, n);
        annotation[n] = '\0';
    }

    virtual ~N() {}

private:
    char annotation[100];
    int value;
};

int main(int argc, char** argv) {
    if (argc < 2) {
        _exit(1);
    }

    N* this_obj = new N(5);

    N* this_00 = new N(6);

    this_obj->setAnnotation(argv[1]);

    this_00->func(this_obj);

    operator delete(this_obj);
    operator delete(this_00);

    return 0;
}
