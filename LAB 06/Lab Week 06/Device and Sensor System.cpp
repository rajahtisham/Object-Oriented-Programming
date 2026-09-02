# include <iostream>
# include <string>
using namespace std;

class Device{
	protected:
	string deviceName;
	int deviceID;
	int* data; 
	
	public:
		Device(string n, int id, int dataSize) {
			deviceName= n;
			deviceID= id;
			data = new int[dataSize];
			cout << "Device constructor: Allocated data for " << deviceName << endl;
		}
		
		virtual ~Device() {
			delete [] data;
			cout << "Device destructor: Freed data for " << deviceName << endl;
		}
	 
};

class Sensor : public Device{
	private:
		string sensorType;
		double* sensorValue;
		
		public:
			Sensor(string n, int id, int dataSize, string type, double val) : Device (n, id, dataSize) {
				sensorType = type;
				sensorValue = new double;
				*sensorValue = val;
				cout << "Sensor constructor: Allocated sensorValue for " << sensorType << endl;
				
			}
			
			~Sensor() {
				delete sensorValue;
				cout << "Sensor destructor : Freed sensorValue for" << sensorType << endl;
			}
			
			void display() {
				cout << "Device: " << deviceName << "|ID: " << deviceID << "|Sensor: " << sensorType << "| Value:" << *sensorValue << endl;
			}
};
 
 int main(){
 	Sensor* s = new Sensor("tempSensor01", 101, 10, "Temperature", 25.6);
 	s->display();
 	cout << "\nDeleting object..." << endl;
 	delete s;
 	return 0;
 }
