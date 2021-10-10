#include"orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string date;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->size = 0;

	while (ifs>>date&& ifs >> stuId&& ifs >> stuName&& ifs >> roomId&& ifs >> status)
	{
		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos-1);
			m.insert(make_pair(key,value));
		}

		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		this->orderData.insert(make_pair(this->size, m));
		this->size++;
	}
};

void OrderFile::updateOrder() {
	if (this->size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->size; i++) {
		ofs << "date:" << this->orderData[i]["date"] << " ";
		ofs << "stuId:" << this->orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderData[i]["roomId"] << " ";
		ofs << "status:" << this->orderData[i]["status"] << endl;
	}
	ofs.close();
};
