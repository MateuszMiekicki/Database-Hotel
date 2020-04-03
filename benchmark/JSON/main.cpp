#include "../build/install/include/benchmark/benchmark.h"

static void findJSON_oneThread(benchmark::State &state)
{
    
    for (auto _ : state)
    {
    }
}
BENCHMARK(findJSON_oneThread);

BENCHMARK_MAIN();
