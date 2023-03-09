#pragma once


template<typename T>
void Safe_Delete_Vector(vector<T>& _vec) {

	//===================================
	//	위 아래 코드의 차이 분석해보기
	//===================================
	
	typename vector<T>::iterator iter = _vec.begin();
	for (; iter != _vec.end(); ++iter) {
		if (*iter != nullptr) {
			delete *iter;
		}
	}
	
	
	/*
	for (size_t i = 0; i < _vec.size(); ++i) {
		if (_vec[i] != nullptr) {
			delete _vec[i];
		}
	}
	*/
	
	
	_vec.clear();
}