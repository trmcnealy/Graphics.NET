

#include "Utilities/GpuCsvReader.hpp"

//#include "Analyzes/PrincipalComponentAnalysis.hpp"

#include <iostream>

//-lruntime.Graphics.NET.$(Platform).dll,
int main(int argc, char* argv[])
{
    int  num_threads      = 4;
    int  num_numa         = 1;
    int  device_id        = 0;
    int  ndevices         = 1;
    int  skip_device      = 9999;
    bool disable_warnings = false;

    Kokkos::InitArguments arguments(num_threads, num_numa, device_id, disable_warnings);

    Kokkos::initialize(arguments);

    // int result = PrincipalComponentAnalysis<double, Kokkos::Cuda>();

    String s(
        "\"Status Date\",\"Status #\",\"API NO.\",\"Operator Name/Number\",\"Lease Name\",\"Well #\",Dist.,County,\"Wellbore Profile\",\"Filing Purpose\",Amend,\"Total Depth\",\"Stacked Lateral Parent Well DP #\",\"Current Queue\"");

    {
        const int index = s.IndexOf(',');

        std::cout << "index = " << index << std::endl;
    }

    {
        const int index = s.IndexOf("API");

        std::cout << "index = " << index << std::endl;
    }

    Kokkos::finalize();

    std::cout << "Press any key to exit." << std::endl;
    getchar();

    return 0;
}
