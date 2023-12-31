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
	// CommandQueue : DX12에 등장
	// 외주를 요쳥할 때, 하나씩 요청하면 비효율적
	// [외주 목록]에 일감을 차곡차곡 기록했다가 한 방에 요청하는 것
	ComPtr<ID3D12CommandQueue>			_cmdQueue;	// 일감을 넣어주는 헬퍼
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc;	// 일감을 넣어주기 위한 메모리 공간 할당
	ComPtr<ID3D12GraphicsCommandList>	_cmdList;	// 일감 리스트

	// Fence : 울타리
	// CPU / GPU 동기화를 위한 간단한 도구
	// 외주를 준 작업이 끝날 때 까지 기다리겠다.
	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>			_swapChain;
	shared_ptr<DescriptorHeap>	_descHeap;
};