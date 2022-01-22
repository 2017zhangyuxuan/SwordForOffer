//
// Created by 张宇轩 on 2021/9/15.
// 面试题2：实现Singleton模式
//

#include "Chapter2.h"
#include <mutex>
#include <iostream>

using namespace std;

//   ----------- 懒汉式，不使用智能指针，需要定义一个内部类来进行垃圾回收------------
namespace t1{
    class Singleton {
    private:
        Singleton(){};
        ~Singleton() { cout << "析构" << endl;}
        static Singleton* instance;         // 不用智能指针的原因：析构函数为private，智能指针不能调用析构函数
        static std::mutex mutex;

        // 定义一个内部类，来做垃圾回收
        class GC {
        public:
            GC() {};
            ~GC() {
                if (instance != nullptr) {
                    delete Singleton::getInstance();
                }
            } ;
        };
        static GC gc;

    public:
        static Singleton* getInstance() {
            if (instance == nullptr ) {
                std::lock_guard<std::mutex> lock(mutex);
                if (instance == nullptr) {
                    instance = new Singleton();
                }
            }
            return instance;
        }
    };

    Singleton::GC Singleton::gc;
    Singleton* Singleton::instance = nullptr;
    std::mutex Singleton::mutex;
}

//   ----------- 懒汉式，使用智能指针，还需要定义一个静态的垃圾回收方法------------
namespace t2{
    class Singleton {
    private:
        Singleton(){}
        ~Singleton() {
            cout << "析构t2" << endl;
            cout << &t2::Singleton::mutex << endl;
        }
        // 这里需要再定义个静态的销毁函数，是因为智能指针销毁类时默认调用类的析构函数，而Singleton的析构函数定义为私有
        static void Destroy(Singleton* singleton){
            if (singleton != nullptr) {
                delete singleton;
                singleton = nullptr;
            }
        }
        static shared_ptr<Singleton> instance;
        static std::mutex mutex;

    public:
        static shared_ptr<Singleton> getInstance() {
            if (instance == nullptr ) {
                std::lock_guard<std::mutex> lock(mutex);
                if (instance == nullptr) {
                    instance = shared_ptr<Singleton>(new Singleton(), Singleton::Destroy);
                }
            }
            return instance;
        }
    };

    shared_ptr<Singleton> Singleton::instance = nullptr;
    std::mutex Singleton::mutex;
}

//   ----------- 懒汉式，推荐使用局部静态变量，简单又方便，C++11 后局部静态变量的初始化是线程安全的------------
namespace t3 {
    class Singleton {
    private:
        Singleton() {}
        ~Singleton() {
            cout << "析构t6" << endl;
        }

    public:
        static Singleton* getInstance(){
            static Singleton instance;
            return &instance;
        }
    };
}

//   ----------- 饿汉式，不用考虑多线程的问题，使用智能指针------------
namespace t4{
    class Singleton {
    private:
        Singleton(){}
        ~Singleton() {
            cout << "析构t3" << endl;
        }
        static void Destroy(Singleton* singleton){
            if (singleton != nullptr) {
                delete singleton;
                singleton = nullptr;
            }
        }
        static shared_ptr<Singleton> instance;

    public:
        static shared_ptr<Singleton> getInstance() {
            return instance;
        }
    };

    shared_ptr<Singleton> Singleton::instance = shared_ptr<Singleton>(new Singleton(),Singleton::Destroy);
}

//   ----------- 饿汉式，instance是对象实例------------
namespace t5{
    class Singleton {
    private:
        Singleton(){}
        ~Singleton() {
            cout << "析构t4" << endl;
        }
        static Singleton instance;

    public:
        static Singleton* getInstance() {
            return &instance;
        }
    };

    Singleton Singleton::instance;
}

//   ----------- 饿汉式，instance是对象指针，需要自定义内部类------------
namespace t6{
    class Singleton {
    private:
        Singleton(){}
        ~Singleton() {
            cout << "析构t5" << endl;
        }
        static Singleton* instance;

        class GC {
        public:
            GC(){}
            ~GC() {
                if (instance != nullptr) {
                    delete instance;
                    instance = nullptr;
                }
            }
        };
        static GC gc;
    public:
        static Singleton* getInstance() {
            return instance;
        }
    };

    Singleton::GC Singleton::gc;
    Singleton* Singleton::instance = new Singleton();
}

void Problem2(){
//    cout << t1::Singleton::getInstance() << endl;
//    cout << t1::Singleton::getInstance() << endl;
//    cout << t1::Singleton::getInstance() << endl;
    cout << t2::Singleton::getInstance() << endl;
    cout << t2::Singleton::getInstance() << endl;
    cout << t2::Singleton::getInstance() << endl;
//    cout << t3::Singleton::getInstance() << endl;
//    cout << t3::Singleton::getInstance() << endl;
//    cout << t3::Singleton::getInstance() << endl;
//    cout << t4::Singleton::getInstance() << endl;
//    cout << t4::Singleton::getInstance() << endl;
//    cout << t4::Singleton::getInstance() << endl;
//    cout << t5::Singleton::getInstance() << endl;
//    cout << t5::Singleton::getInstance() << endl;
//    cout << t5::Singleton::getInstance() << endl;
//    cout << t6::Singleton::getInstance() << endl;
//    cout << t6::Singleton::getInstance() << endl;
//    cout << t6::Singleton::getInstance() << endl;
    cout << "Problem2 End" << endl;

}

