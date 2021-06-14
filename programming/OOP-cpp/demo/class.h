
class Anny{
    private:
        int value;
    public:
        Anny(){};
        Anny(int v){
            value = v;
        };
        Anny(Anny &obj){
            this->value = obj.getValue();
        };
        ~Anny(){};
        int getValue(){
            return value;
        }
};
