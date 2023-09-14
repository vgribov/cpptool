#pragma once

template <typename F>
struct DeferredAction
{
    DeferredAction(F f) : action{f} {}
    ~DeferredAction() { action(); }
    F action;
};

template <typename F>
DeferredAction<F> defer(F f)
{
    return DeferredAction<F>{f};
}
