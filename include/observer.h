//
// Created by Henrique Pagnossi on 2024-02-20.
//
#pragma once

namespace dl {

    template <class T>
    class IObserver {
    public:
        virtual ~IObserver() = default;
        virtual void on_notify(T& data) = 0;
    };

    template <class T>
    class ISubject
    {
    public:
        virtual void attach(IObserver<T>* observer) = 0;
        virtual void detach(IObserver<T>* observer) = 0;
    };
} // dl