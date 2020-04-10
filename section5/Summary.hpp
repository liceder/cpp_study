// Copyright (c) 2020 by Chrono

#ifndef _SUMMARY_HPP
#define _SUMMARY_HPP

#include "cpplang.hpp"
#include "SalesData.hpp"
#include "SpinLock.hpp"

BEGIN_NAMESPACE(cpp_study)

class Summary final
{
public:
    using this_type = Summary;
public:
    using sales_type        = SalesData;
    using lock_type         = SpinLock;
    using lock_guard_type   = SpinLockGuard;

    using string_type       = std::string;
    using map_type          =
            std::map<string_type, sales_type>;
public:
    Summary() = default;
   ~Summary() = default;

    Summary(const Summary&) = delete;
    Summary& operator=(const Summary&) = delete;
private:
    lock_type   m_lock;
    map_type    m_sales;
public:
    void add_sales(const sales_type& s)
    {
        lock_guard_type guard(m_lock);

        m_sales[s.id()].inc_sold(s.sold());
        m_sales[s.id()].inc_revenue(s.revenue());
    }
};

END_NAMESPACE(cpp_study)

#endif  //_SUMMARY_HPP

