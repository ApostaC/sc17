echo "======================testing xscblat1"
./testing/xscblat1 >> testOut
echo "======================testing xdcblat1"
./testing/xdcblat1 >> testOut
echo "======================testing xccblat1"
./testing/xccblat1 >> testOut
echo "======================testing xzcblat1"
./testing/xzcblat1 >> testOut
echo "======================testing xscblat2 sin2"
./testing/xscblat2 < testing/sin2 >> testOut
echo "======================testing xdcblat2 din2"
./testing/xdcblat2 < testing/din2 >> testOut 
echo "======================testing xscblat2 cin2"
./testing/xccblat2 < testing/cin2 >> testOut 
echo "======================testing xzcblat2 zin2"
./testing/xzcblat2 < testing/zin2 >> testOut
echo "======================testing sin3"
./testing/xscblat3 < testing/sin3 >> testOut
echo "======================testing din3"
./testing/xdcblat3 < testing/din >> testOut
echo "======================testing cin3"
./testing/xccblat3 < testing/cin3 >> testOut
echo "======================testing zin3"
./testing/xzcblat3 < testing/zin3 >> testOut 
