#ifndef LAB4_1_EXAMPLE_H
#define LAB4_1_EXAMPLE_H


class example {
        int _element;
    public:
        example() {}
        example(int element)
        {
            _element = element;
        }
        int get() {
            return _element;
        }
        void set_element(int element){
            _element = element;
        }
};


#endif //LAB4_1_EXAMPLE_H
