#include <stdint.h>

static inline void cpuid( int code, uint32_t * a, uint32_t * d )
{
    asm volatile( "cpuid"
                  : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx");
}
static inline int cpuid_string(int code, uint32_t where[4]) {
  asm volatile("cpuid":"=a"(*where),"=b"(*(where+1)),
               "=c"(*(where+2)),"=d"(*(where+3)):"a"(code));
  return (int)where[0];
}
static inline void rdtsc( uint32_t * upper, uint32_t * lower )
{
    asm volatile( "rdtsc"
                  : "=a"(*lower), "=d"(*upper) );
}
static inline unsigned read_cr0( void )
{
    unsigned val;
    asm volatile( "mov %%cr0, %0"
                  : "=r"(val) );
    return val;
}

