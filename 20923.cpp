#include <iostream>
#include <deque>

using namespace std;
// �׶��忡 �ִ� ���� �� (src1) �� �ڽ��� �� (src2)�� �ڽ��� ��(des)�� ��ġ�� �Լ�
void mergeCards(deque<int>& src1, deque<int>& src2, deque<int>& des) {
	while (!src1.empty()) {
		des.push_back(src1.back()); // ���浦�� �����(�� �� �ں���) �Ʒ��� ��ġ��
		src1.pop_back();
	}
	while (!src2.empty()) {
		des.push_back(src2.back());// �ڽ��� ���� �����(�� �� �ں���) �Ʒ��� ��ġ��
		src2.pop_back();
	}
}

string playGame(int m, deque <int>& dodo, deque <int>& su) {
	deque<int> do_gr; //�׶��忡 �ִ� ������ ī�� ����
	deque<int> su_gr; // �׶��忡 �ִ� ������ ī�� ����
	bool flag = true; // true�� ���� ������ ����, false �� ����  ������ ����

	while (m--) {
		if (flag) {
			do_gr.push_front(dodo.front()); // ���� �ִ� �� ���� ī�带 �׶��忡 ���´�
			dodo.pop_front();
			if (dodo.empty()) return "su";// ���� �ִ� ī���� ���� 0�� �Ǹ� ������ ��� �¸�
		}
		else {
			su_gr.push_front(su.front()); /// ���� �ִ� �� ���� ī�带 �׶��忡 ���´�
			su.pop_front();
			if (su.empty()) return "do";// ���� �ִ� ī���� ���� 0�� �Ǹ� ������ ��� �¸�
		}
		flag = !flag; //���� �ٲٱ�
		//������ �����̰� ���� ĥ �� �ִ��� �˻�
		if (!do_gr.empty() && do_gr.front() == 5 || !su_gr.empty() && su_gr.front() == 5) mergeCards(su_gr, do_gr, dodo);
		if (!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5) mergeCards(do_gr, su_gr, su);
	}

	if (dodo.size() > su.size()) return "do";
	else if (dodo.size() < su.size()) return "su";
	return "dosu";
}
/*
   *[���� �Ҹ����� ����] : ����, �ùķ��̼�
	 * ����,�������� ���� �׶��忡 �ִ� ����,������ �� �� 4���� ���� �������ָ� �˴ϴ�
	 * deque ���̺귯���� ����ϸ� ī�� ������ �Ͼ�� �ϵ��� ���� ������ �� �ֽ��ϴ�
	 * �������� �־��� ���� ���� ������� �����ϸ� �˴ϴ�
	 * ������ ���� ���� �Ǵ� �������� ���� ī�尡 ���� '���' ���ᰡ �Ǵ� �� �Դϴ�
*/
int main() {
	int n, m;
	cin >> n >> m;
	deque<int> dodo;
	deque<int> su;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dodo.push_front(a);
		su.push_front(b);
	}

	cout << playGame(m, dodo, su);
	return 0;
}
