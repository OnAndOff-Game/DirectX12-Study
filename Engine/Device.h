#pragma once

// �η� �繫��
// GPU�� ��ȣ�ۿ��� �ϱ� ���� �繫��?
// ���� ��ü�� �����ϰų� �ϴ� �κ��� ���
class Device
{
public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }

private:
	// COM(Componenet Object Model)
	// - DX�� ���α׷��� ��� �������� ���� ȣȯ���� �����ϰ� �ϴ� ���
	// - COM ��ü(COM �������̽�)�� ���. ���λ����� �츮���� ������
	// - ComPtr ������ ����Ʈ ������
	ComPtr<ID3D12Debug>		_debugController;
	ComPtr<IDXGIFactory>	_dxgi;	// ȭ�� ���� ��ɵ�
	ComPtr<ID3D12Device>	_device;// ���� ��ü ����
};