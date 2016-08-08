//
// HubPage.xaml.h
// HubPage 类的声明
//

#pragma once

#include "HubPage.g.h"

using namespace Windows::UI::ViewManagement;

namespace HubApp1
{
	/// <summary>
	/// 显示分组的项集合的页。
	/// </summary>
	public ref class HubPage sealed
	{
	public:
		HubPage();

		static void RegisterDependencyProperties();
		static property Windows::UI::Xaml::DependencyProperty^ DefaultViewModelProperty
		{
			Windows::UI::Xaml::DependencyProperty^ get() { return _defaultViewModelProperty; }
		}

		static property Windows::UI::Xaml::DependencyProperty^ NavigationHelperProperty
		{
			Windows::UI::Xaml::DependencyProperty^ get() { return _navigationHelperProperty; }
		}

		/// <summary>
		/// 可将其更改为强类型视图模型。
		/// </summary>
		property Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^ DefaultViewModel
		{
			Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^  get();
		}
		/// <summary>
		/// NavigationHelper 在每页上用于协助导航和
		/// 进程生命期管理
		/// </summary>
		property HubApp1::Common::NavigationHelper^ NavigationHelper
		{
			HubApp1::Common::NavigationHelper^ get();
		}

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		Windows::ApplicationModel::Resources::ResourceLoader^ _resourceLoader;

		void LoadState(Platform::Object^ sender, HubApp1::Common::LoadStateEventArgs^ e);
		void ItemView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void GroupSection_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);

		static Windows::UI::Xaml::DependencyProperty^ _defaultViewModelProperty;
		static Windows::UI::Xaml::DependencyProperty^ _navigationHelperProperty;
	};
}
