#include <chrono>

class KPStopwatch
{
public:
    using clock = std::chrono::steady_clock;
    using time_point = std::chrono::time_point<clock, std::chrono::milliseconds>;

    KPStopwatch() = default;
protected:
    enum class State : unsigned char;

    static constexpr time_point current_time() noexcept
    {
        return std::chrono::time_point_cast<std::chrono::milliseconds>(clock::now());
    }
public:
    virtual void reset() noexcept
    {
        clock_state = State::idle;
    }

    time_point go() noexcept
    {
        if (clock_state != State::stopped)
            start_point = current_time();

        clock_state = State::running;
        return start_point;
    }

    void stop() noexcept
    {
        if (clock_state == State::running)
        {
            stop_point = current_time();
            clock_state = State::stopped;
        }
    }

    std::chrono::nanoseconds elapsed_time() const noexcept
    {
        switch (clock_state)
        {
        case State::idle:
            return std::chrono::duration_cast<std::chrono::milliseconds>(clock::duration::zero());

        case State::running:
            return std::chrono::duration_cast<std::chrono::milliseconds>(current_time() - start_point);

        case State::stopped:
            return std::chrono::duration_cast<std::chrono::milliseconds>(stop_point - start_point);

        default:
            return std::chrono::duration_cast<std::chrono::milliseconds>(clock::duration::zero());
            break;
        }
    }

protected:
    enum class State : unsigned char { idle, running, stopped };

    time_point start_point;
    time_point stop_point;
    State      clock_state = State::idle;
};