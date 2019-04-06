#pragma once
class IdHellper {
	int id;

	static int current_id; // added

	IdHellper() : id(current_id++) {} // added
};