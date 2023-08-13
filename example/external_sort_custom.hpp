#ifndef EXTERNAL_SORT_CUSTOM_HPP
#define EXTERNAL_SORT_CUSTOM_HPP

/// ----------------------------------------------------------------------------
/// custom type to run external sort for

// Below is an example how to define and use external_sort with custom type!

struct CustomRecord
{
  union {
    uint32_t i32[4];
    uint16_t i16[8];
    uint8_t i8[16];
  } u;
};

struct CustomRecordComparator
{
    bool operator()(const CustomRecord& x, const CustomRecord& y) const {
	if (x.u.i32[1] == y.u.i32[1]) { 
       	// Datetime
	  return x.u.i32[0] < y.u.i32[0];
        }
	// IP
	return x.u.i32[1] < y.u.i32[1];
    }
};

struct CustomRecord2Str
{
    std::string operator()(const CustomRecord& x)
    {
        std::ostringstream ss;
        ss << (boost::format("(%d; %d; %d; %d;)")
               % x.u.i32[0] % x.u.i32[1] % x.u.i32[2] % x.u.i32[3]);
        return ss.str();
    }
};

namespace external_sort {
template <>
struct ValueTraits<CustomRecord>
{
    using Comparator = CustomRecordComparator;
    using Value2Str = CustomRecord2Str;

    // default generator with all random bytes:
    using Generator = DefaultValueGenerator<CustomRecord>;
};
}

#endif
