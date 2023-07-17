#pragma once

class SwapChain;
class DescriptorHeap;

class CommandQueue
{
public:
	~CommandQueue();

	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain, shared_ptr<DescriptorHeap> descHeap);
	void WaitSync();

	void RnederBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();

	ComPtr<ID3D12CommandQueue> GetCmdQueue() { return _cmdQueue; }
private:
	// CommandQueue : DX12�� ����
	// ���ָ� �䫊�� ��, �ϳ��� ��û�ϸ� ��ȿ����
	// [���� ���]�� �ϰ��� �������� ����ߴٰ� �� �濡 ��û�ϴ� ��
	ComPtr<ID3D12CommandQueue>			_cmdQueue;	// �ϰ��� �־��ִ� ����
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc;	// �ϰ��� �־��ֱ� ���� �޸� ���� �Ҵ�
	ComPtr<ID3D12GraphicsCommandList>	_cmdList;	// �ϰ� ����Ʈ

	// Fence : ��Ÿ��
	// CPU / GPU ����ȭ�� ���� ������ ����
	// ���ָ� �� �۾��� ���� �� ���� ��ٸ��ڴ�.
	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>			_swapChain;
	shared_ptr<DescriptorHeap>	_descHeap;
};